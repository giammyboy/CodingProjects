#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string s("Hello");
    std::cout << s << std::endl;
    for (int i = 0; i < s.size(); i++) {
        std::cout << i << s[i] << std::endl;
    }
    for (auto it = s.begin(); it != s.end(); it++) {
        std::cout << *it << std::endl;
    }

    std::vector<int> v(3, 1);
    for (auto it = v.rbegin(); it != v.rend(); it++) {
        std::cout << *it << std::endl;
    }
    return 0;
}
