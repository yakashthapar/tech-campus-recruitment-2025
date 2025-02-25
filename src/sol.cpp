#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./sol YYYY-MM-DD" << std::endl;
        return 1;
    }

    std::string target_date = argv[1];  
    std::string target_year = target_date.substr(0, 4); // Extract year (YYYY)
    std::string log_file = "logs_" + target_year + ".log"; // Construct filename

    std::ifstream file(log_file);
    if (!file) {
        std::cerr << "Error: Unable to open log file: " << log_file << std::endl;
        return 1;
    }

    std::string line;
    std::string output_file = "output/output_" + target_date + ".txt";
    std::ofstream output(output_file);
    
    bool found = false;
    while (std::getline(file, line)) {
        if (line.find(target_date) == 0) {  // Check if line starts with the date
            found = true;
            output << line << std::endl;  // Write to output file
        }
    }

    if (!found) {
        std::cout << "No logs found for " << target_date << std::endl;
    } else {
        std::cout << "Logs for " << target_date << " saved to " << output_file << std::endl;
    }

    return 0;
}
