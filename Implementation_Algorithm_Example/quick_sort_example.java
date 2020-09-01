public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] array = new int[n];
        int idx = 0;
        for (int i = 0; i < n; i++) {
            array[idx++] = Integer.parseInt(br.readLine());
        }

        quicksort(array, 0, array.length - 1);
        for (int v : array) {
            bw.write(v + "\n");
        }
        bw.flush();
        bw.close();

    }

    private static int partition(int[] array, int left, int right) {
        int mid = (left + right) / 2;
        swap(array, left, mid);

        int pivot = array[left];
        int i = left, j = right;

        while (i < j) {
            while (pivot < array[j]) {
                j--;
            }

            while (i < j && pivot >= array[i]) {
                i++;
            }
            swap(array, i, j);
        }
        array[left] = array[i];
        array[i] = pivot;
        return i;
    }

    private static void swap(int[] array, int a, int b) {
        int temp = array[b];
        array[b] = array[a];
        array[a] = temp;
    }

    private static void quicksort(int[] array, int left, int right) {
        if (left >= right) return;

        int pi = partition(array, left, right);
        quicksort(array, left, pi - 1);
        quicksort(array, pi + 1, right);
    }

}