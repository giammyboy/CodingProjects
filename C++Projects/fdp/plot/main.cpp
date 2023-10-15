#include <matplot/matplot.h>
#include <vector>
#include <cmath>


using namespace matplot;

std::vector<double> f(std::vector<double> t) {
    return transform(t, [](auto t) {return pow(t, 3); });
}

int main() {

    auto x = linspace(-5, 5, 100);

    plot(x, f(x))->line_width(3);
    title("Test Graph");
    xlabel("x");
    ylabel("y");

    show();

    return 0;
}