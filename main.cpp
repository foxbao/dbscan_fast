
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <sys/time.h>

#include "dbscan.hpp" //<-- include dbscan library

using namespace std;
std::vector<std::string> splitWithStl(const std::string &str, const std::string &pattern)
{
    std::vector<std::string> resVec;

    if ("" == str)
    {
        return resVec;
    }
    //方便截取最后一段数据
    std::string strs = str + pattern;

    size_t pos = strs.find(pattern);
    size_t size = strs.size();

    while (pos != std::string::npos)
    {
        std::string x = strs.substr(0, pos);
        resVec.push_back(x);
        strs = strs.substr(pos + 1, size);
        pos = strs.find(pattern);
    }

    return resVec;
}

float stringToFloat(const string &i)
{
    using namespace std;
    stringstream sf;
    float score = 0;
    sf << i;
    sf >> score;
    return score;
}

std::vector<std::vector<float>> openFile(char *filename)
{
    // std::vector<vec3f> dataset;
    using namespace std;
    fstream file;
    file.open(filename, ios::in);
    if (!file)
    {
        cout << "Open File Failed!" << endl;
    }

    int idx_pt = 0;
    std::vector<std::vector<float>> dataset;
    while (!file.eof())
    {
        string temp;
        file >> temp;
        std::vector<std::string> resVec = splitWithStl(temp, ",");
        stringToFloat(resVec[0]);
        std::vector<float> data;
        data.push_back(stringToFloat(resVec[0]));
        data.push_back(stringToFloat(resVec[1]));
        dataset.push_back(data);
    }
    file.close();
    cout << "successful!" << endl;
    return dataset;
}

int main(int argc, char *argv[])
{

    int minPoints = 4;
    float epsilon = 40;
    std::vector<std::vector<float>> data;

    data = openFile("feature.txt");
    struct timeval t1, t2;
    for (int i = 0; i < 10; i++)
    {
        gettimeofday(&t1, NULL);
        dbscan(data, epsilon, minPoints);
        gettimeofday(&t2, NULL);
        double deltaT = (t2.tv_sec - t1.tv_sec) * 1000000 + t2.tv_usec - t1.tv_usec;
        std::cout << "time_comsumed:" << deltaT / 1000000 << std::endl;
    }

    return 0;
}