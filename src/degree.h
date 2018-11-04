
using namespace std;

enum Degree {SECURITY, NETWORK, SOFTWARE, NONE};

// Converts from a string to a Degree
Degree parseToDegree(string degree) {
    if (degree == "SECURITY") {
        return Degree(SECURITY);
    } else if (degree == "NETWORK") {
        return Degree(NETWORK);
    } else if (degree == "SOFTWARE") {
        return Degree(SOFTWARE);
    } else {
        return Degree(NONE);
    }
}

// Converts a Degree to a string
string parseFromDegree(Degree degree) {
    // cout << "Degree to parse is: " << degree <<endl;
    if (degree == Degree(SECURITY)) {
        return "Security";
    } else if (degree == Degree(NETWORK)) {
        return "Network";
    } else if (degree == Degree(SOFTWARE)) {
        return "Software";
    } else {
        return "NONE";
    }
}
