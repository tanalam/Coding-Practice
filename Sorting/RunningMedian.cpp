/*
Fraudulent Activity Notifications
https://www.hackerrank.com/challenges/fraudulent-activity-notifications/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=sorting
*/
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'activityNotifications' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY expenditure
 *  2. INTEGER d
 */
void makeFreq(vector<int>& freq, vector<int>& exp, int d)
{
    for (int i = 0; i < d; ++i)
    {
        ++freq[exp[i]];
    }
}

double getMedian(vector<int>& freq, int d)
{
    if (d % 2 == 0)
    {
        int middle = d / 2 - 1;
        int count = 0;

        for (unsigned i = 0; i <= freq.size(); i++)
        {
            count += freq[i];
            if (count > middle)
            {
                if(count > (middle+1))
                {
                    return (double)(i);
                }
                int ans = i;
                
                while(freq[++i] == 0 && i < freq.size())
                {
                    ;
                }
                ans += i;
                return (double)ans/2;
            }
        }
    }
    else
    {
        int middle = d / 2;
        int count = 0;
        for (unsigned i = 0; i <= freq.size(); i++)
        {
            count += freq[i];
            if (count > middle)
            {
                return (double)(i);
            }
        }
    }
    return 0;
}
int activityNotifications(vector<int> expenditure, int d) {
    int count = 0;
    double median = 0;
    const int SIZE = 201;
    vector<int> freq(SIZE, 0);
    makeFreq(freq, expenditure, d);
    for (unsigned i = d; i < expenditure.size(); ++i)
    {
        median = getMedian(freq, d);
        if (2.0*median <= expenditure[i])
        {
            count++;
        }
        freq[expenditure[i - d]]--;
        freq[expenditure[i]]++;
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int d = stoi(first_multiple_input[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split(rtrim(expenditure_temp_temp));

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
