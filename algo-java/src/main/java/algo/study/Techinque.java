package algo.study;

import java.util.Arrays;

public class Techinque {

    /**
     * https://velog.io/@pshsh910/Java-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%ED%92%80-%EB%95%8C-%EC%9C%A0%EC%9A%A9%ED%95%9C-%EB%A9%94%EC%84%9C%EB%93%9C%EB%93%A4
     */
    public void techinque1() {
        char c = '1';
        int out = Character.getNumericValue(c);

        if (Character.isDigit(c));


        // String.replaceAll
        String numbers = "zero one two three four five six seven eight nine";
        String[] zeroToNine = {"zero", "one", "two", "three", "four", "five","six", "seven", "eight", "nine"};
        for(int i = 0; i < zeroToNine.length; i++) {
            numbers = numbers.replaceAll(zeroToNine[i], String.valueOf(i));
        }

        // override osrt
        Integer[][] arr2 = {{1, 2}, {1, 1}, {5, 5}};
        Arrays.sort(arr2, (o1, o2) -> {
            if (o1[0] == o2[0]) return o1[1] - o2[1];
            else return o1[0] - o2[0];
        });
    }

    public void print() {
        Integer[] arr = {1, 2, 3, 4, 5};
        System.out.println(Arrays.toString(arr));
    }

    public void string() {
        String answer = "123";
        for (char c : answer.toCharArray()) {
            System.out.println(c);
        }
    }


    // compare 결과는 param left > 1, same 0, param right > -1 기억하기
    public int compare(int m1, int s1, int m2, int s2) {
        if (m1 == m2) return Integer.compare(s1, s2);
        return Integer.compare(m1, m2);
    }

    /*
     * 2. 배열도 스트림 사용하는 법 : Arrays.stream(arr)
     * 3. 스트림 형 변환 방법 : stream().mapToInt(Integer::parseInt) -> 원시타입 int로 변환됨 주의
     * 4. 원시타입int 배열을 래퍼클래스Integer로 변환 : arr.boxed().toArray(Integer[]::new);
     */
    public void primitiveAndWrapper() {
        int[] arr = {1, 2, 3, 4, 5};
        Integer[] arr2 = Arrays.stream(arr).boxed().toArray(Integer[]::new);
        System.out.println(arr2.toString());
    }
}
