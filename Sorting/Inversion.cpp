/*
https://www.hackerrank.com/challenges/ctci-merge-sort/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=sorting
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


long merge(vector<int>& arr, vector<int>& out, int l, int m, int r)
{
    int i=l;
    int j=m+1;
    int k=l;
    long count=0;
    while(i <= m && j <= r)
    {
        if(arr[i] <= arr[j])
        {
            out[k++] = arr[i++];
        }
        else
        {
            out[k++] = arr[j++];            
            count += (m - i+1);
        }
    }
    //copy remain
    while(i <= m)
    {
        out[k++] = arr[i++];
    }
    while(j <= r)
    {
        out[k++] = arr[j++];
    }        

    //copyto main
    for(int i=l;i<=r;i++)
    {
        arr[i]=out[i];
    }
    return count;
}

long mergeSort(vector<int>& arr, vector<int>& out, int l, int r)
{
    long count=0;
    int m = l + (r-l)/2;
    if( l >= r)
    {
        return count;
    }
    count += mergeSort(arr,out,l,m);
    count += mergeSort(arr,out,m+1,r);
    count += merge(arr,out,l,m,r);
    return count;
}
/*
 * Complete the 'countInversions' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

long countInversions(vector<int>& arr) {
    vector<int> out(arr.size(),0);
    return mergeSort(arr,out,0,arr.size()-1);
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split(rtrim(arr_temp_temp));

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        long result = countInversions(arr);

        fout << result << "\n";
    }

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
