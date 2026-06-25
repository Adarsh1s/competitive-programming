class Solution {
    unordered_map<size_t,string> map;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        size_t key = hash<string>{} (longUrl);
        while(map.count(key) && map[key] != longUrl) key++;
        map[key] = longUrl;
        return "http://tinyurl.com/"+ to_string(key);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        size_t key= stoull(shortUrl.substr(shortUrl.rfind('/')+1));
        return map[key];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));