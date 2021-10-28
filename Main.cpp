const int hashKey = 100019; // random prime number > 1e6
long long encrypt(pair<int, int> p) {
    long long res = p.first;
    res = res * hashKey + p.second;
    return res;
}
int stringDiscover(string s)
{
    int time = 0;
    pair<int, int> init = {0,0};
    map<pair<long long, long long>, int> path;

    for (auto x : s) {
        pair<long long, long long> hashedPath;
        hashedPath.first = encrypt(init);
        if (x == 'E') init.first += 1;
        else if (x == 'W') init.first -= 1;
        else if (x == 'S') init.second -= 1;
        else init.second += 1;

        hashedPath.second = encrypt(init);

        // sort
        // first element of stored path always larger 
        if (hashedPath.first < hashedPath.second) 
            swap(hashedPath.first, hashedPath.second);

        // find if path already traversed
        if (path[hashedPath] == NULL) {
            path[hashedPath] = 1;
            time += 3;
        }
        else time += 1;
    }

    return time;
}
