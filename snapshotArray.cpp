class SnapshotArray {
public:
    int nshot;
   unordered_map<int,set<pair<int,int>,greater<pair<int,int>>>>m;

    SnapshotArray(int length) {
        nshot = 0;
        m.clear();
    }
    
    void set(int index, int val) {
        auto it = m[index].lower_bound({nshot -1, INT_MAX});
        if(it != m[index].end() && it -> first == nshot - 1){
            m[index].erase(it);

        }   
        m[index].insert({nshot - 1, val});     
    }
    
    int snap() {
        nshot++;
        return nshot - 1;
        
    }
    
    int get(int index, int snap_id) {
        return (((m[index]).lower_bound({snap_id,0}))->second);
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
