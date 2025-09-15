class Solution
{
public:
    int canBeTypedWords(string text, string brokenLetters)
    {
        int result = 0;
        vector<int> freq_map(26);
        for (int i = 0; i < brokenLetters.size(); i++)
        {
            freq_map[brokenLetters[i]-'a']++;
        }
        string word = "";
        bool cant = false;
        int total_words = 1;
        int cant_type = 0;
        for (int i = 0; i < text.size(); i++)
        {
            if (text[i] == ' ')
            {
                total_words++;
                if (cant)
                {
                    cant_type++;
                    cant = false;
                }
            }
            else
            {

                if (freq_map[text[i] - 'a'])
                {
                    cant = true;
                }
            }
        }
        if (cant)
        {
            cant_type++;
        }

        return total_words - cant_type;
    }
};