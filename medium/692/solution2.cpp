class Solution {
public:
    typedef pair<string, int> Pair;
    static bool allCompare(const Pair &p1, const Pair &p2) {
        if( p1.second == p2.second ) {
            // same freq, sort with alphabatic order
            auto minPsize = p1.first.size() < p2.first.size() ? p1.first.size() : p2.first.size();
            for( auto i = 0; i < minPsize; i++ ) {
                if( p1.first[i] < p2.first[i] )
                    return true;
                else if( p1.first[i] > p2.first[i] )
                    return false;
                else continue;
            }
            return p1.first.size() < p2.first.size() ? true : false;
        }
	    return p1.second > p2.second;
    }
    static bool alphaCompare(const string &p1, const string &p2) {
            // same freq, sort with alphabatic order
            auto minPsize = p1.size() < p2.size() ? p1.size() : p2.size();
            for( auto i = 0; i < minPsize; i++ ) {
                if( p1[i] < p2[i] )
                    return true;
                else if( p1[i] > p2[i] )
                    return false;
                else continue;
            }
            return p1.size() < p2.size() ? true : false;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        // O(nlogn) - re-sort the words vector by alphabatical order
        sort( words.begin(), words.end(), alphaCompare );
        
        // O(n) - accumulate same string and transform into freq(vec)
        vec.push_back( Pair(words[0], 0) );
        vecIdx = 0;
        for( auto i = 1; i < words.size(); i++ ) {
            if( words[i] == words[i-1] ) {
                vec[vecIdx].second++;
            }
            else {
                vec.push_back( Pair(words[i], 0) );
                vecIdx++;
            }
        }
        
        // O(nlogn) - sort with value, if same value sort with alphabatical order
        sort( vec.begin(), vec.end(), allCompare );
        
        // O(k) - output to out vector
        auto iter = vec.begin();
        for( auto i = 0; i < k; i++ ) {
            out.push_back(iter->first);
            ++iter;
        }
        return out;
    }
private:
    int vecIdx;
    vector<Pair> vec;
    vector<string> out;
};
