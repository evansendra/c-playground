#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main ()
{
    fstream file
    (
        "high-scores.txt",
        ios::in | ios::out // open for reading and writing
    );

    // check if file opened
    if (!file.is_open())
    {
        cout << "Could not open file" << endl;
        return 0;
    }

    // get new score from user
    int new_score;
    cout << "Enter new score." << endl;
    cin >> new_score;

    // read to point in file where score should be inserted
    int cur_score;
    streampos pre_score_pos = file.tellg();
    while (file >> cur_score && cur_score > new_score)
    {
        pre_score_pos = file.tellg(); 
    }

    // ensure we didn't hit eof b/c of a fail
    if (file.fail() && !file.eof())
    {
        cout << "Bad score/read -- exiting." << endl;
        return 1;
    }

    file.clear();

    // store rest of scores in a vector
    file.seekg(pre_score_pos);
    vector<int> old_scores;
    while (file >> cur_score)
    {
        old_scores.push_back(cur_score);
    }

    // ensure we hit eof by reading rest of scores
    if (!file.eof())
    {
        cout << "Bad score/read -- exiting." << endl;
        return 1;
    }
    
    file.clear();

    // write score, followed by scores in vector
    file.seekp(pre_score_pos);
    
    // write a newline in case we're not at beginning of file
    // b/c cursor will be at the position after # before newline
    if (file.tellp() != std::streampos(0))
        file << endl;

    file << new_score << endl;
    for (int i : old_scores)
    {
       file << i << endl; 
    }

    return 0;
}
