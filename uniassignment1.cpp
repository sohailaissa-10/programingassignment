
#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

void readScores(int scores[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> scores[i];
    }
}

double computeAverage(const int scores[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += scores[i];
    }
    return static_cast<double>(sum) / n;
}

void analyzeResults(const int scores[], int n,
                    int &minScore,
                    int &maxScore,
                    int &passCount,
                    int &failCount)
{
    minScore = scores[0];
    maxScore = scores[0];
    passCount = 0;
    failCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (scores[i] < minScore)
            minScore = scores[i];

        if (scores[i] > maxScore)
            maxScore = scores[i];

        if (scores[i] >= 50)
            passCount++;
        else
            failCount++;
    }
}

int main()
{
    int n;
    cin >> n;

    int scores[MAX_SIZE];

    readScores(scores, n);

    double average = computeAverage(scores, n);

    int minScore, maxScore;
    int passCount, failCount;

    analyzeResults(scores, n, minScore, maxScore, passCount, failCount);

    cout << "Average score: " << average << endl;
    cout << "Maximum score: " << maxScore << endl;
    cout << "Minimum score: " << minScore << endl;
    cout << "Passed students: " << passCount << endl;
    cout << "Failed students: " << failCount << endl;

    cout << "Scores above average: ";
    for (int i = 0; i < n; i++)
    {
        if (scores[i] > average)
            cout << scores[i] << " ";
    }
    cout << endl;

    return 0;
}

