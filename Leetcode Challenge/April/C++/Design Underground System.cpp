class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> checkInM; // Uid - {StationName, Time}
    unordered_map<string, pair<int, int>> path; // RouteName - {TotalTime, Count}
    
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        checkInM[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto checkIn = checkInM[id];
        checkInM.erase(id); 
            
        string pathName = checkIn.first + "_" + stationName;
        path[pathName].first += t - checkIn.second;
        path[pathName].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string routeName = startStation + "_" + endStation;
        auto& route = path[routeName];
        return (double) route.first / route.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
