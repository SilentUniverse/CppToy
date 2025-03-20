#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<int> getPidByCmd(const std::string& cmd) {
    std::vector<int> pids;
    std::ifstream procDir("/proc");
    if (!procDir.is_open()) {
        std::cerr << "Failed to open /proc directory" << std::endl;
        return pids;
    }

    std::string entry;
    while (std::getline(procDir, entry)) {
        // Check if the entry is a valid PID directory
        if (entry.length() > 0 && entry[0] >= '0' && entry[0] <= '9') {
            std::ifstream statusFile("/proc/" + entry + "/status");
            if (!statusFile.is_open()) {
                continue;
            }

            std::string line;
            while (std::getline(statusFile, line)) {
                if (line.find("Name:") == 0) {
                    size_t colonPos = line.find(':');
                    if (colonPos != std::string::npos) {
                        std::string processName = line.substr(colonPos + 1);
                        // Remove any leading/trailing whitespace
                        processName.erase(0, processName.find_first_not_of(" \t"));
                        processName.erase(processName.find_last_not_of(" \t") + 1);

                        if (processName == cmd) {
                            pids.push_back(std::stoi(entry));
                        }
                    }
                    break; // No need to read further lines after finding Name
                }
            }
            statusFile.close();
        }
    }
    procDir.close();

    return pids;
}

int main() {
    std::string cmd = "systemd-logind"; // Replace with the command you want to find
    std::vector<int> pids = getPidByCmd(cmd);

    if (pids.empty()) {
        std::cout << "No processes found for command: " << cmd << std::endl;
    } else {
        std::cout << "PIDs for command '" << cmd << "': ";
        for (int pid : pids) {
            std::cout << pid << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Program completed successfully." << std::endl;
    return 0;
}
