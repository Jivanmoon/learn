#include<bits/stdc++.h>
void word_count_pro(std::unordered_map<std::string, int>& m)
{
	std::string word;
	while (std::cin >> word)
	{
		word.erase(std::remove_if(word.begin(), word.end(), ispunct),
			word.end());
        std::for_each(word.begin(), word.end(), [](char &c){c = tolower(c);});
		++m[word];
	}
	for (const auto& e : m) std::cout << e.first << " : " << e.second << "\n";
}

int main()
{
	std::unordered_map<std::string, int> m;
	word_count_pro(m);

	return 0;
}