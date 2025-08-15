#include "../../include/physics/PhysicsEngine.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <cstddef>

class Tetster {
public:
    explicit Tetster(PhysicsEngine& engine) : engine_(engine) {}

    void run_all() {
        auto fall_path  = test_basic_fall();
        auto horiz_path = test_horizontal_motion();
        test_timestep_influence_visual(); // покажем и движок, и референс

        std::cout << "\n=== Basic fall ===\n";
        print_path_compact(fall_path, 80);

        std::cout << "\n=== Horizontal motion ===\n";
        print_path_compact(horiz_path, 80);
    }

private:
    PhysicsEngine& engine_;

    // ==== печать компактно: (x,y) × N ====
    static std::size_t dedup_size(const std::vector<Coordinate>& path) {
        if (path.empty()) return 0;
        std::size_t cnt = 1;
        for (std::size_t i = 1; i < path.size(); ++i) {
            if (path[i].x != path[i - 1].x || path[i].y != path[i - 1].y) ++cnt;
        }
        return cnt;
    }

    static void print_path_compact(const std::vector<Coordinate>& path, std::size_t max_rows) {
        if (path.empty()) { std::cout << "(empty)\n"; return; }
        std::size_t printed = 0;
        Coordinate cur = path[0];
        std::size_t run = 1;

        for (std::size_t i = 1; i < path.size(); ++i) {
            const Coordinate& p = path[i];
            if (p.x == cur.x && p.y == cur.y) {
                ++run;
            } else {
                if (printed < max_rows)
                    std::cout << "(" << cur.x << ", " << cur.y << ") × " << run << "\n";
                ++printed;
                cur = p;
                run = 1;
            }
        }
        if (printed < max_rows)
            std::cout << "(" << cur.x << ", " << cur.y << ") × " << run << "\n";
        ++printed;

        if (printed > max_rows)
            std::cout << "... +" << (printed - max_rows) << " more lines\n";

        const Coordinate& first = path.front();
        const Coordinate& last  = path.back();
        std::cout << "start=(" << first.x << ", " << first.y << "), "
                  << "end=("   << last.x  << ", "  << last.y  << "), "
                  << "total steps=" << path.size()
                  << ", distinct="   << dedup_size(path) << "\n";
    }

    // ==== референсная парабола (на double), независимая от движка/карты ====
    static std::vector<Coordinate> simulate_parabola_double(
            double startX, double startY,
            double v0, double angleDeg,
            double gravity, double dt,
            std::size_t maxSteps,
            double groundY /*обычно 0*/)
    {
        const double PI = 3.14159265358979323846;
        const double rad = angleDeg * PI / 180.0;

        double vx = v0 * std::cos(rad);
        double vy = v0 * std::sin(rad);

        double x = startX;
        double y = startY;

        std::vector<Coordinate> path;
        path.reserve(maxSteps + 1);

        for (std::size_t i = 0; i < maxSteps; ++i) {
            // сохраняем, округляя к целым клеткам — как ты видишь карту
            path.emplace_back(
                static_cast<coordinate_value_t>(std::lround(x)),
                static_cast<coordinate_value_t>(std::lround(y))
            );

            // шаг Эйлера
            vy += -gravity * dt;
            x  += vx * dt;
            y  += vy * dt;

            if (y <= groundY) break; // условно "земля" на уровне groundY
        }
        return path;
    }

    // ==== Тесты движка ====
    std::vector<Coordinate> test_basic_fall() {
        Coordinate start(10, 50); // выше — чтобы было видно падение
        Coordinate v(0, 0);

        auto path = engine_.count_ballistics(
            start, v,
            static_cast<gravity_t>(9.8),
            static_cast<time_step_t>(0.02),
            static_cast<std::size_t>(400)
        );

        bool ok = true;
        for (std::size_t i = 1; i < path.size(); ++i)
            if (path[i].y - path[i - 1].y > 1e-9) ok = false;
        std::cout << "[Fall test] " << (ok ? "OK" : "FAIL") << "\n";
        return path;
    }

    std::vector<Coordinate> test_horizontal_motion() {
        Coordinate start(10, 50);
        Coordinate v(60, 0); // ощутимый горизонтальный сдвиг

        auto path = engine_.count_ballistics(
            start, v,
            static_cast<gravity_t>(9.8),
            static_cast<time_step_t>(0.02),
            static_cast<std::size_t>(400)
        );

        bool ok = path.size() > 1 && path[1].x > path[0].x;
        std::cout << "[Horizontal test] " << (ok ? "OK" : "FAIL") << "\n";
        return path;
    }

    // ==== Тест 3: сравнение — движок vs ре
