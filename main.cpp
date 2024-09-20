#include <iostream>
#include "UnitTests.h"

int main() {
    int choice, subchoice, testType;
    while (true) {
        std::cout << "Choose a category:\n";
        std::cout << "1. Graph tests\n";
        std::cout << "2. Graph coloring tests\n";
        std::cout << "3. Shortest path tests\n";
        std::cout << "4. Exit\n";
        std::cout << "Your choice: ";
        std::cin >> choice;

            switch (choice) {
        case 1:
            std::cout << "Choose a test type:\n";
            std::cout << "1. Automatic Test\n";
            std::cout << "2. Manual Test\n";
            std::cout << "Your choice: ";
            std::cin >> testType;
            switch (testType) {
                case 1:
                    std::cout << "Choose a test:\n";
                    std::cout << "1. Undirected graph test\n";
                    std::cout << "2. Directed graph test\n";
                    std::cout << "Your choice: ";
                    std::cin >> subchoice;
                    switch (subchoice) {
                        case 1:
                            testUndirectedGraphAuto();
                            break;
                        case 2:
                            testDirectedGraphAuto();
                            break;
                        default:
                            std::cout << "Invalid choice\n";
                            break;
                    }
                    break;
                case 2:
                    std::cout << "Choose a test:\n";
                    std::cout << "1. Undirected graph test\n";
                    std::cout << "2. Directed graph test\n";
                    std::cout << "Your choice: ";
                    std::cin >> subchoice;
                    switch (subchoice) {
                        case 1:
                            testUndirectedGraphManual();
                            break;
                        case 2:
                            testDirectedGraphManual();
                            break;
                        default:
                            std::cout << "Invalid choice\n";
                            break;
                    }
                    break;
                default:
                    std::cout << "Invalid choice\n";
                    break;
            }
            break;
        case 2:
            std::cout << "Choose a test type:\n";
            std::cout << "1. Automatic Test\n";
            std::cout << "2. Manual Test\n";
            std::cout << "Your choice: ";
            std::cin >> testType;
            switch (testType) {
                case 1:
                    std::cout << "Choose a test:\n";
                    std::cout << "1. Undirected graph coloring test\n";
                    std::cout << "2. Directed graph coloring test\n";
                    std::cout << "Your choice: ";
                    std::cin >> subchoice;
                    switch (subchoice) {
                        case 1:
                            testUndirectedGraphColoringAuto();
                            break;
                        case 2:
                            testDirectedGraphColoringAuto();
                            break;
                        default:
                            std::cout << "Invalid choice\n";
                            break;
                    }
                    break;
                case 2:
                    std::cout << "Choose a test:\n";
                    std::cout << "1. Undirected graph coloring test\n";
                    std::cout << "2. Directed graph coloring test\n";
                    std::cout << "Your choice: ";
                    std::cin >> subchoice;
                    switch (subchoice) {
                        case 1:
                            testUndirectedGraphColoringManual();
                            break;
                        case 2:
                            testDirectedGraphColoringManual();
                            break;
                        default:
                            std::cout << "Invalid choice\n";
                            break;
                    }
                    break;
                default:
                    std::cout << "Invalid choice\n";
                    break;
            }
            break;
        case 3:
            std::cout << "Choose a test type:\n";
            std::cout << "1. Automatic Test\n";
            std::cout << "2. Manual Test\n";
            std::cout << "Your choice: ";
            std::cin >> testType;
            switch (testType) {
                case 1:
                    std::cout << "Choose a test:\n";
                    std::cout << "1. Undirected graph shortest path test\n";
                    std::cout << "2. Directed graph shortest path test\n";
                    std::cout << "Your choice: ";
                    std::cin >> subchoice;
                    switch (subchoice) {
                        case 1:
                            testUndirectedGraphShortestPathAuto();
                            break;
                        case 2:
                            testDirectedGraphShortestPathAuto();
                            break;
                        default:
                            std::cout << "Invalid choice\n";
                            break;
                    }
                    break;
                case 2:
                    std::cout << "Choose a test:\n";
                    std::cout << "1. Undirected graph shortest path test\n";
                    std::cout << "2. Directed graph shortest path test\n";
                    std::cout << "Your choice: ";
                    std::cin >> subchoice;
                    switch (subchoice) {
                        case 1:
                            testUndirectedGraphShortestPathManual();
                            break;
                        case 2:
                            testDirectedGraphShortestPathManual();
                            break;
                        default:
                            std::cout << "Invalid choice\n";
                            break;
                    }
                    break;
                default:
                    std::cout << "Invalid choice\n";
                    break;
            }
            break;
        case 4:
            std::cout << "Exiting the program...\n";
            return 0;
        default:
            std::cout << "Invalid choice\n";
            break;
        }
    }
}
