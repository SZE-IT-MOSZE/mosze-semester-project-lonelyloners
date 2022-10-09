#include <string>
#include <vector>

class Command {
    private:
        std::string command;
        std::vector<std::string> commands = {"MOVE"};
        std::vector<std::string> items {"1", "2", "3", "4", "5"};
        int command_id;
        int item_id;

        bool validate(std::string command);

    public:
        Command(std::string cm);
        void make();
        int getCommandId();
        int getItemId();
};