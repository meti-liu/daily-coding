#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <cstdlib> // For getenv()

std::string getCurrentDirectory() {
    char* cwd = getenv("PWD"); // Linux/Unix 环境下获取当前目录
    if (cwd != nullptr) {
        return std::string(cwd);
    }
    return ".";
}

void applyOffsetToDRL(const std::string& inputFilePath, const std::string& outputFilePath, int dx, int dy) {
    std::ifstream inputFile(inputFilePath);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open input file. Path: " << inputFilePath << std::endl;
        return;
    }

    std::ofstream outputFile(outputFilePath);
    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not open output file. Path: " << outputFilePath << std::endl;
        return;
    }

    std::cout << "Processing file: " << inputFilePath << std::endl;
    std::cout << "Output file: " << outputFilePath << std::endl;

    std::string line;
    std::regex coordinateRegex(R"(X(-?\d+)Y(-?\d+))"); // Match X and Y coordinates
    std::smatch match;

    while (std::getline(inputFile, line)) {
        if (std::regex_search(line, match, coordinateRegex)) {
            int x = std::stoi(match[1].str());
            int y = std::stoi(match[2].str());

            // Apply offsets
            int newX = x + dx;
            int newY = y + dy;

            // Replace the original coordinates with updated values
            std::string updatedLine = std::regex_replace(line, coordinateRegex, "X" + std::to_string(newX) + "Y" + std::to_string(newY));
            outputFile << updatedLine << "\n";
        }
        else {
            // Write the line unchanged
            outputFile << line << "\n";
        }
    }

    std::cout << "Processing complete." << std::endl;
    inputFile.close();
    outputFile.close();
}

int main() {
    std::string inputFilePath = "N-TOP-A-UP.drl";
    std::string outputFilePath = "N-TOP-A-UP-offset.drl";

    std::cout << "Current working directory: " << getCurrentDirectory() << std::endl;

    int dx = 1000; // Offset in X direction
    int dy = 2000; // Offset in Y direction

    applyOffsetToDRL(inputFilePath, outputFilePath, dx, dy);

    return 0;
}

