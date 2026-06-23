#include "recommender.h"

void recommend(Result first,
               Result best,
               Result worst)
{
    double score1 =
        first.utilization -
        first.totalFragmentation;

    double score2 =
        best.utilization -
        best.totalFragmentation;

    double score3 =
        worst.utilization -
        worst.totalFragmentation;

    cout << "\n===================================";
    cout << "\nSMART RECOMMENDATION";
    cout << "\n===================================\n";

    if(score1 >= score2 &&
       score1 >= score3)
    {
        cout << "First Fit is recommended.\n";
    }
    else if(score2 >= score1 &&
            score2 >= score3)
    {
        cout << "Best Fit is recommended.\n";
    }
    else
    {
        cout << "Worst Fit is recommended.\n";
    }
}