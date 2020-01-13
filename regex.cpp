
#include <regex>
#include <string>
#include <iostream>

int main()
{
    std::cmatch cm;
    std::smatch sm;
    std::regex rgx("sun[^ ]*");
    std::regex seg_rgx("(sun)([^ ]*)");
    std::regex not_rgx("(?!.*shining)(.*)");
    std::regex yes_rgx("(.*)(sunset)(.*)(sunrise)(.*)");
    std::string poem("if you weeped for the missing sunset you would miss all the shining stars. someday,you will find the one£¬who will watch every sunrise with you until the sunset of your life");
    
    // regex_search
    if (std::regex_search(poem, rgx)) {
		std::cout << "regex_search : find a word start with sun int the poem" << std::endl;
	}

    if (std::regex_search(poem.begin(),poem.end(), rgx)) {
        std::cout << "regex_search : find a word start with sun int the poem" << std::endl;
    }

	auto temp_poem = poem;
    std::cout << "reg search ¡­¡­" << std::endl;
	while (std::regex_search(temp_poem, sm, rgx)) {
		for (auto ref : sm) {
            std::cout << "    " << ref << std::endl;
		}
		temp_poem = sm.suffix().str();
	}

    temp_poem = poem;
    std::cout << "seg_reg search ¡­¡­" << std::endl;
	while (std::regex_search(temp_poem, sm, seg_rgx)) {
		for (auto ref : sm) {
            std::cout << "    " << ref << std::endl;
		}
		temp_poem = sm.suffix().str();
	}
    
    // regex_match
    if (!std::regex_match(poem.begin(),poem.end(), not_rgx)) {
        std::cout << "regex_match : find a word shining int the poem" << std::endl;
    }

	if (std::regex_match(poem, yes_rgx)) {
		std::cout << "regex_match : find a ¡­¡­sunset¡­¡­sunrise¡­¡­ format int the poem" << std::endl;
	}

	if (std::regex_match(poem.begin(), poem.end(), yes_rgx)) {
		std::cout << "regex_match : find a ¡­¡­sunset¡­¡­sunrise¡­¡­ format int the poem" << std::endl;
	}

    std::regex_match(poem, sm, yes_rgx);
    std::regex_match(poem.c_str(), cm, yes_rgx);

    std::cout << "cm.size() == sm.size() ? (0 | 1) : " << (cm.size() == sm.size()) << std::endl;

    // regex_replace
    std::cout << std::regex_replace(poem, rgx, "") << std::endl;
    std::cout << std::regex_replace(poem, seg_rgx, "") << std::endl;

    std::string replace_poem;
    std::regex_replace(std::back_inserter(replace_poem), poem.begin(), poem.end(), rgx, "");
    std::cout << "std::back_inserter mode : " << std::endl << replace_poem << std::endl;

    std::cout << std::regex_replace(poem, seg_rgx, "$1down") << std::endl;
    std::cout << std::regex_replace(poem, seg_rgx, "rain$2") << std::endl;
    std::cout << std::regex_replace(poem, seg_rgx, "raindown") << std::endl;
    std::cout << std::regex_replace(poem, seg_rgx, "[$1 - $2]", std::regex_constants::format_no_copy) << std::endl;

    return 0;
}