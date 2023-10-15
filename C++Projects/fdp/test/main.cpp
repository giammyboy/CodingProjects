#include <matplot/matplot.h>
#include <cmath>

using namespace matplot;

std::vector<double> f(std::vector<double> t) {
    return transform(t, [](auto t) {return pow(t, 3); });
}

int main() {

    auto x = linspace(-5, 5, 10000);

    title("Test Graph");
    xlabel("x");
    ylabel("y");
    plot(x, f(x))->line_width(2);

    show();
    
    return 0;
}
