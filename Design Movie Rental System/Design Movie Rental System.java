// Solution for Design Movie Rental System in JAVA

class MovieRentingSystem {
    Map<Integer, TreeSet<int[]>> available = new HashMap<>();
    Map<String, Integer> price = new HashMap<>();
    TreeSet<int[]> rented = new TreeSet<>((a,b) ->
        a[0]!=b[0]?a[0]-b[0] : a[1]!=b[1]?a[1]-b[1] : a[2]-b[2]);

    public MovieRentingSystem(int n, int[][] entries) {
        for (int[] e : entries) {
            int shop = e[0], movie = e[1], p = e[2];
            available.computeIfAbsent(movie, k -> new TreeSet<>(
                (a,b)-> a[0]!=b[0]?a[0]-b[0] : a[1]-b[1])).add(new int[]{p,shop});
            price.put(shop+"#"+movie, p);
        }
    }

    public List<Integer> search(int movie) {
        List<Integer> res = new ArrayList<>();
        if (available.containsKey(movie)) {
            for (int[] x : available.get(movie)) {
                res.add(x[1]);
                if (res.size()==5) break;
            }
        }
        return res;
    }

    public void rent(int shop, int movie) {
        int p = price.get(shop+"#"+movie);
        available.get(movie).remove(new int[]{p,shop});
        rented.add(new int[]{p,shop,movie});
    }

    public void drop(int shop, int movie) {
        int p = price.get(shop+"#"+movie);
        available.get(movie).add(new int[]{p,shop});
        rented.remove(new int[]{p,shop,movie});
    }

    public List<List<Integer>> report() {
        List<List<Integer>> res = new ArrayList<>();
        for (int[] x : rented) {
            res.add(Arrays.asList(x[1],x[2]));
            if (res.size()==5) break;
        }
        return res;
    }
}
