class Solution {
public:
    string validIPAddress(string queryIP) {
        // Check if the IP is IPv4
        if (queryIP.find('.') != string::npos) {
            return isIPv4(queryIP) ? "IPv4" : "Neither";
        }
        // Check if the IP is IPv6
        else if (queryIP.find(':') != string::npos) {
            return isIPv6(queryIP) ? "IPv6" : "Neither";
        }
        // If neither IPv4 nor IPv6 format
        return "Neither";
    }

private:
    // Checks if the IP is a valid IPv4 address
    bool isIPv4(const string &ip) {
        int count = 0;
        string part;
        for (auto ch : ip) {
            if (ch == '.') {
                if (!isValidIPv4Part(part)) return false;  // Validate each part
                count++;
                part.clear();
            } else {
                part += ch;
            }
        }
        if (!isValidIPv4Part(part)) return false;  // Validate the last part
        return count == 3;  // IPv4 should have exactly 3 dots and 4 parts
    }

    // Checks if a part of the IPv4 address is valid
    bool isValidIPv4Part(const string &part) {
        if (part.empty() || part.size() > 3) return false;  // Part length check
        if (part[0] == '0' && part.size() > 1) return false;  // Prevent leading zeros
        for (char ch : part) {
            if (!isdigit(ch)) return false;  // Only digits are allowed
        }
        int num = stoi(part);
        return num >= 0 && num <= 255;  // Valid range for IPv4 parts
    }

    // Checks if the IP is a valid IPv6 address
    bool isIPv6(const string &ip) {
        int count = 0;
        string part;
        for (char ch : ip) {
            if (ch == ':') {
                if (!isValidIPv6Part(part)) return false;  // Validate each part
                count++;
                part.clear();
            } else {
                part += ch;
            }
        }
        if (!isValidIPv6Part(part)) return false;  // Validate the last part
        return count == 7;  // IPv6 should have exactly 7 colons and 8 parts
    }

    // Checks if a part of the IPv6 address is valid
    bool isValidIPv6Part(const string &part) {
        if (part.empty() || part.size() > 4) return false;  // Part length check (1-4 chars)
        for (char ch : part) {
            if (!isxdigit(ch)) return false;  // Only hexadecimal digits are allowed (0-9, a-f, A-F)
        }
        return true;
    }
};
