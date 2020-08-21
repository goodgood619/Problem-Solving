import java.util.*;
class Solution {
    public String[] solution (String[]record){
            String[] answer = {};
            Map<String, String> map = new HashMap<>();
            int cnt = 0;
            for (String value : record) {
                String[] strArr = value.split(" ");
                String menu = strArr[0], uid = strArr[1];
                if (menu.equals("Enter")) {
                    String nickname = strArr[2];
                    if (map.get(uid) == null) {
                        map.put(uid, nickname);
                    } else {
                        map.remove(uid);
                        map.put(uid, nickname);
                    }
                    cnt++;
                } else if (menu.equals("Change")) {
                    map.remove(uid);
                    map.put(uid, strArr[2]);
                } else cnt++;
            }

            answer = new String[cnt];
            int idx = 0;
            for (String s : record) {
                String[] arr = s.split(" ");
                String menu = arr[0], uid = arr[1];
                if (menu.equals("Enter")) {
                    String enterNickname = map.get(uid);
                    answer[idx++] = enterNickname + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";
                } else if (menu.equals("Leave")) {
                    String leaveNickname = map.get(uid);
                    answer[idx++] = leaveNickname + "´ÔÀÌ ³ª°¬½À´Ï´Ù.";
                }
            }
            return answer;
        }
}