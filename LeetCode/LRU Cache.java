class LRUCache {
    // put의 경우 맨 뒤에 넣는다, 근데 만약에 꽉찼으면, head를 제거하고 맨 뒤에 넣는다
    // get의 경우 제거를 하는데, 그 위치값을 제거를 한다
    
    class Node {
        int key;
        int value;
        Node prev;
        Node next;
        Node(int key,int value) {
            this.key = key;
            this.value = value;
        }
    }
    Node head=null;
    Node tail = null;
    Map<Integer,Node> map = new HashMap<>();
    int capacity=0;
    public LRUCache(int capacity) {
        this.capacity = capacity;
    }
    
    public int get(int key) {
        if(map.get(key)==null) return -1;
        
        Node cur = map.get(key);
        removeNode(cur);
        putNode(cur);
        return cur.value;
    }
    
    public void put(int key, int value) {
        if(map.get(key)!=null) {
            //이미 존재를 하니까, 기존에 있는 위치에 있는것을 지우고
            // 맨뒤에 새로운 value를 삽입
            Node cur = map.get(key);
            cur.value = value;
            
            removeNode(cur);
            putNode(cur);
        }
        else {
            //존재를 안하니까 , 그냥 넣으면 되는데, 사이즈가 크면 안됨
            //사이즈가 크면, head를 움직인다
            if(map.size()>=capacity) {
                map.remove(head.key);
                removeNode(head);
            }
            // 그다음에 끝에 넣는다
            Node cur = new Node(key,value);
            putNode(cur);
            map.put(key,cur);
        }
        
    }
    
    private void removeNode(Node cur) {
        // 만약 이전이 null이 아님 ->  
        if(cur.prev!=null) {
            cur.prev.next = cur.next;
        }
        //null이면 지워야하는 위치가 head임
        else {
            head = cur.next;
        }
        // 만약 다음이 null이 아님
        if(cur.next!=null) {
            cur.next.prev = cur.prev;
        }
        //지워야하는 위치가 꼬리
        else {
            tail = cur.prev;
        }
    }
    private void putNode(Node cur) {
        //끝에 넣는다
        if(tail!=null) {
            tail.next = cur;
            cur.prev = tail;
            cur.next = null;
        }
        tail = cur;
        //만약 head가 null이면 head와 tail이 똑같겠지 그리고, head는 가만히 우선은 정지해있지
        if(head==null) {
            head = tail;
        }
    }
}


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */