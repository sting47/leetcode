class Solution {
public:
    static bool my_compare(const pair<string, int> &p1, const pair<string, int> &p2) {
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
    vector<string> topKFrequent(vector<string>& words, int k) {
        // go through each element and insert it into map
        for( auto i = 0; i < words.size(); i++ ) {
            doInput2Map(words[i]);
        }
        
        // transform map to vector
        vector<pair<string, int>> vec;

	    for( auto itr = freqCnt.begin(); itr != freqCnt.end(); ++itr ) {
		    vec.push_back(make_pair(itr->first, itr->second));
	    }
        
        // sort with value
        sort( vec.begin(), vec.end(), my_compare );
        
        // output to out vector
        auto iter = vec.begin();
        for( auto i = 0; i < k; i++ ) {
            out.push_back(iter->first);
            ++iter;
        }
        return out;
    }
private:
    map<string, int> freqCnt;
    vector<string> out;
    void doInput2Map(string word) {
        auto iter = freqCnt.find(word);
        if( iter != freqCnt.end() ) {
            freqCnt[word]++;
        }
        else {
            freqCnt[word] = 1;
        }
    }
};
