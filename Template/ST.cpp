// Truy vấn: A(i) = v
// Hàm cập nhật trên cây ST, cập nhật cây con gốc id quản lý đọan [l, r]
void update(int id, int l, int r, int i, int v) {
    if (i < l || r < i) {
        // i nằm ngoài đoạn [l, r], ta bỏ qua nút i
        return ;
    }
    if (l == r) {
        // Đoạn chỉ gồm 1 phần tử, không có nút con
        ST[id] = v;
        return ;
    }

    // Gọi đệ quy để xử lý các nút con của nút id
    int mid = (l + r) / 2;
    update(id*2, l, mid, i, v);
    update(id*2 + 1, mid+1, r, i, v);

    // Cập nhật lại giá trị max của đoạn [l, r] theo 2 nút con:
    ST[id] = max(ST[id*2], ST[id*2 + 1]);
}

// Truy vấn: tìm max đoạn [u, v]
// Hàm tìm max các phần tử trên cây ST nằm trong cây con gốc id - quản lý đoạn [l, r]
int get(int id, int l, int r, int u, int v) {
    if (v < l || r < u) {
        // Đoạn [u, v] không giao với đoạn [l, r], ta bỏ qua đoạn này
        return -INFINITY;
    }
    if (u <= l && r <= v) {
        // Đoạn [l, r] nằm hoàn toàn trong đoạn [u, v] mà ta đang truy vấn, ta trả lại
        // thông tin lưu ở nút id
        return ST[id];
    }
    int mid = (l + r) / 2;
    // Gọi đệ quy với các con của nút id
    return max(get(id*2, l, mid, u, v), get(id*2 + 1, mid+1, r, u, v));
}

// tpl2
class SegmentTree{
private :
    vector < int > Tree;
    vector< int > p;
public :
    int merge(int a , int b){ return max(a,b);}
    void build(int node , int l , int r){
		if ( l == r ){
			Tree[node] = p[l-1];
			return;
		}
		int mid = l + r >> 1;
		build(node*2,l,mid);
		build(node*2+1,mid+1,r);
		Tree[node] = merge(Tree[node*2],Tree[node*2+1]);
	}
    int get(int node , int l , int r , int x , int y){
		if ( l > y || r < x) return 0;
		if ( x <= l && r <= y ) return Tree[node];
		int mid = l + r >> 1;
		int a = get(node*2,l,mid,x,y);
		int b = get(node*2+1,mid+1,r,x,y);
		return merge(a,b);
	}
    SegmentTree ( vector<int> p){
        int sz = p.size();
        Tree.assign(4*sz+5,0) ;
        this->p = p;
    }
};