import java.util.*;

public class GenerateBinaryNumbers {
    public static void main(String[] args) {
        int n = 10;

        Queue<String> queue = new LinkedList<>();
        queue.add("1");

        for (int i = 1; i <= n; i++) {
            String binary = queue.poll();
            System.out.println(binary);

            queue.add(binary + "0");
            queue.add(binary + "1");
        }
    }
}
