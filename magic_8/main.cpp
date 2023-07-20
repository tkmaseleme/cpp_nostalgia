#include <iostream>
#include <cstdlib>
#include <ctime>

std::string getMagic8BallResponse() {
    std::string responses[] = {
        "It is certain.",
        "It is decidedly so.",
        "Without a doubt.",
        "Yes, definitely.",
        "No, You.",
        "As I see it, Your Face!",
        "Most likely.",
        "Do Not Be Sorry, Be Better",
        "Give Me Thanos!!!",
        "Signs point to yes.",
        "Reply hazy, try again.",
        "I will cook you in the blood of your offspring. ",
        "Better not tell you now.",
        "Sometimes I wonder if I really want a job.",
        "Concentrate and ask again.",
        "Don't count on it.",
        "My reply is no.",
        "Have you considered seeing a professional?",
        "Outlook not so good.",
        "Very doubtful."
    };

    int totalResponses = sizeof(responses) / sizeof(responses[0]);
    int randomIndex = std::rand() % totalResponses;
    return responses[randomIndex];
}

void displayResponseWithFrame(const std::string& response) {
    int width = response.length() + 4;
    std::string border(width, '*');
    std::string space(width - 2, ' ');

    std::cout << border << std::endl;
    std::cout << "*" << space << "*" << std::endl;
    std::cout << "* " << response << " *" << std::endl;
    std::cout << "*" << space << "*" << std::endl;
    std::cout << border << std::endl;
}

int main() {
    std::cout << "**************************************************\n";
    std::cout << "*       Welcome to the Magic 8 Ball!             *\n";
    std::cout << "**************************************************\n\n";
    std::string question;

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    while (true) {
        std::cout << "Ask a yes or no question (or type 'q' to quit): ";
        std::getline(std::cin, question);

        if (question == "q" || question == "Q") {
            break;
        }

        std::string response = getMagic8BallResponse();
        displayResponseWithFrame(response);
    }

    std::cout << "Goodbye!\n";
    return 0;
}
