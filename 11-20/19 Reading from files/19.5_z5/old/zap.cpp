
#include<iostream>
#include<fstream>
#include<filesystem>

int main() {
    std::ofstream file_1("questions.txt", std::ios::out | std::ios::app);
    std::ofstream file_2("answers.txt", std::ios::out | std::ios::app);
    setlocale(LC_ALL, "ru_RU.utf8");

    // if (!file.eof()) {
    //     std::cout << "Error! The file was not opened!" << std::endl;
    //     return -1;
    // } 

    std::string text [] {
        "<Question 1>",
        "An example of English humor: an Englishman who filled out an application for an Australian visa,",
        "having reached one of the points, asked: \"Is it really still necessary to get to Australia?\"",
        "What point has this Englishman reached?",
        "",
        "<Question 2>",
        "In 1896, Emperor Nicholas II emphasized the first word in a certain list, which included Aphrodite,",
        "Vladimir, Yagudiel, Azard and others. This word was not known to all residents of the Russian Empire.",
        "However, with the light hand of the emperor, it became well known, and in Soviet times it was known",
        "by everyone from young to old. Name the word.",
        "",
        "<Question 3>",
        "This is given to a person twice. Each time is free, and if a person wants to have it for the third time,",
        "then they will have to pay for it.",
        "What's it?",
        "",
        "<Question 4>",
        "What did the writer Ramon Gomez de la Serna say: \"It's always stolen\"?",
        "",
        "<Question 5>",
        "The French say: \"The first covers his mistakes with a facade, the second with sauce, and the third with earth.\"",
        "The first is an architect, the second is a cook. Name the third one.",
        "",
        "<Question 6>",
        "There was a husband and wife, a brother and sister, and a brother-in-law and son-in-law. How many are there in total?",
        "",
        "<Question 7>",
        "The ancient Indians called it parapushta, that is, \"nurtured by another.\" And what do we call it?",
        "",
        "<Question 8>",
        "In ancient Greece, the creditor installed a sign on the debtor's land, which meant that in case of non-payment of",
        "the debt, it would become the property of the creditor. What was the name of this sign?",
        "",
        "<Question 9>",
        "Now everyone knows what \"prime time\" is. And where do people work who allocate \"drive time\" in the day and pay special",
        "attention to it?",
        "",
        "<Question 10>",
        "There were mother-in-law and son-in-law, husband and wife, grandmother and granddaughter, mother and daughter,",
        "and daughter and father. How many are there in total?",
        "",
        "<Question 11>",
        "These familiar pets were valued so highly in Germany back in the XIV century that in some bills of sale they were",
        "indicated in the list of movable property, which the seller conceded along with the farm. What kind of animals are these?",
        "",
        "<Question 12>",
        "When visiting Jaipur, all tourists can visit the Amber Palace complex, located high on the mountain on an exotic transport",
        "for most of us. Before that, they must climb a kind of tower about three meters high. Who are we talking about?",
        "",
        "<Question 13>",
        "In Russia, this was first started in the time of Peter the Great, and the main center of its production was the city of Shuya.",
        "Since then, the coat of arms of Shui depicts a piece of something that is not only hard these days. What is it?",
        ""
    };

    std::string text_2[] {
        "<Question 1>",
        "conviction",
        "",
        "<Question 2>",
        "Aurora",
        "",
        "<Question 3>",
        "teeth",
        "",
        "<Question 4>",
        "honey",
        "",
        "<Question 5>",
        "doctor",
        "",
        "<Question 6>",
        "trio",
        "",
        "<Question 7>",
        "cuckoo",
        "",
        "<Question 8>",
        "mortgage",
        "",
        "<Question 9>",
        "radio",
        "",
        "<Question 10>",
        "four",
        "",
        "<Question 11>",
        "cats",
        "",
        "<Question 12>",
        "elephant",
        "",
        "<Question 13>",
        "soap",
        ""
    };

    for (auto iter : text) {        
        file_1 << iter << "\r\n";
    }

    for (auto iter : text_2) {
        file_2 << iter << "\r\n";
    }


    system("pause");
    file_1.close();
    file_2.close();
    return 0;
}