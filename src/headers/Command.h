#include <string>
#include <vector>

class Command {
    private:
        std::string input;
        std::vector<std::string> commands = {"FEL", "LE", "JOBBRA", "BALRA", "ELORE", "HATRA", "SEGITSEG", "HELP"};
        std::vector<std::string> items {"1", "2", "3", "4", "5"};
        std::string command;
        std::string item;

        bool validate(std::string command);

    public:
        Command(std::string cm);
        void make();
        std::string getCommand() const;
        std::string getItem() const;
};