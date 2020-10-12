#include <cmath>

#include <TMath.h>

#include "NTagCalculator.hh"

float Norm(const float vec[3])
{
    return sqrt(vec[0]*vec[0] + vec[1]*vec[1] + vec[2]*vec[2]);
}

float Norm(float x, float y, float z)
{
    return sqrt(x*x + y*y + z*z);
}

float GetDistance(const float vec1[3], const float vec2[3])
{
    float tmpVec[3];

    for (int i = 0; i < 3; i++)
        tmpVec[i] = vec1[i] - vec2[i];

    return Norm(tmpVec);
}

float GetLegendreP(int i, float& x)
{
    float result = 0.;

    switch (i) {
        case 1:
            result = x; break;
        case 2:
            result = (3*x*x-1)/2.; break;
        case 3:
            result = (5*x*x*x-3*x)/2; break;
        case 4:
            result = (35*x*x*x*x-30*x*x+3)/8.; break;
        case 5:
            result = (63*x*x*x*x*x-70*x*x*x+15*x)/8.; break;
    }

    return result;
}

float GetTRMS(const std::vector<float>& T)
{
    int   nHits  = T.size();
    float tMean = 0.;
    float tVar  = 0.;

    for (int iHit = 0; iHit < nHits; iHit++)
        tMean += T[iHit] / nHits;
    for (int iHit = 0; iHit < nHits; iHit++)
        tVar += (T[iHit]-tMean)*(T[iHit]-tMean) / nHits;

    return sqrt(tVar);
}

int GetNhitsFromStartIndex(const std::vector<float>& T, int startIndex, float tWidth)
{
    int searchIndex = startIndex;
    int nHits       = T.size();

    while (1) {
        searchIndex++;
        if ((searchIndex > nHits-1) || (TMath::Abs((T[searchIndex] - T[startIndex])) > tWidth))
            break;
    }
    // Return number of hits within the time window
    return TMath::Abs(searchIndex - startIndex);
}

float GetQSumFromStartIndex(const std::vector<float>& T, const std::vector<float>& Q, int startIndex, float tWidth)
{
    int nHits       = Q.size();
    int searchIndex = startIndex;
    float sumQ      = 0.;

    while (1) {
        sumQ += Q[searchIndex];
        searchIndex++;
        if ((searchIndex > nHits-1) || (TMath::Abs((T[searchIndex] - T[startIndex])) > tWidth))
            break;
    }
    // Return total hit charge within the time window
    return sumQ;
}

float GetTRMSFromStartIndex(const std::vector<float>& T, int startIndex, float tWidth)
{
    int nHits = T.size();
    int searchIndex = startIndex;
    std::vector<float> tList;

    while (1) {
        tList.push_back(T[searchIndex]);
        searchIndex++;
        if ((searchIndex > nHits -1) || (TMath::Abs((T[searchIndex] - T[startIndex])) > tWidth))
            break;
    }

    return GetTRMS(tList);
}

int GetNhitsFromCenterTime(const std::vector<float>& T, float centerTime, float tWidth)
{
    int NXX = 0;

    for (const auto& t: T) {
        if (t < centerTime - tWidth/2.) continue;
        if (t > centerTime + tWidth/2.) break;
        NXX++;
    }

    return NXX;
}