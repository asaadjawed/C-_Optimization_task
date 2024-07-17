#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <chrono>

std::string naiveConcatenation(const std::vector<std::string>& strings) {
    std::string result;
    for (const auto& s : strings) {
        result += s; 
    }
    return result;
}
std::string optimizedConcatenation(const std::vector<std::string>& strings) {
    std::ostringstream oss; 
    for (const auto& s : strings) {
        oss << s; 
    }
    return oss.str();
}

int main() {
    const int NUM_STRINGS = 10000; 
    std::vector<std::string> testStrings(NUM_STRINGS, "sample");
    auto startTime = std::chrono::high_resolution_clock::now();
    std::string naiveResult = naiveConcatenation(testStrings);
    auto endTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> naiveTime = endTime - startTime;
    std::cout << "Naive Concatenation Duration: " << naiveTime.count() << " seconds\n";

    startTime = std::chrono::high_resolution_clock::now();
    std::string optimizedResult = optimizedConcatenation(testStrings);
    endTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> optimizedTime = endTime - startTime;
    std::cout << "Optimized Concatenation Duration: " << optimizedTime.count() << " seconds\n";

    return 0;
}



////GIT HUB REPO////
// https://github.com/asaadjawed/C-_Optimization_task //