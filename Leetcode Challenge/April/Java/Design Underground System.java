class UndergroundSystem {
    Map<Integer, Pair<String, Integer>> checkInMap = new HashMap<>();  // Uid - {StationName, Time}
    Map<String, Pair<Double, Integer>> routeMap = new HashMap<>(); // RouteName - {TotalTime, Count}

    public UndergroundSystem() {}

    public void checkIn(int id, String stationName, int t) {
        checkInMap.put(id, new Pair<>(stationName, t));
    }

    public void checkOut(int id, String stationName, int t) {
        Pair<String, Integer> checkIn = checkInMap.get(id);
        checkInMap.remove(id); // Remove after using it which will not make HashTable big

        String routeName = checkIn.getKey() + "_" + stationName;
        int totalTime = t - checkIn.getValue();

        Pair<Double, Integer> route = routeMap.getOrDefault(routeName, new Pair<>(0.0, 0));
        routeMap.put(routeName, new Pair<>(route.getKey() + totalTime, route.getValue() + 1));
    }

    public double getAverageTime(String startStation, String endStation) {
        String routeName = startStation + "_" + endStation;
        Pair<Double, Integer> trip = routeMap.get(routeName);
        return trip.getKey() / trip.getValue();
    }
}
