# 24 - Dãy con có tổng bằng k.
Quay lui để giải quyết bài toán. Dùng vector để lưu kết quả của các dãy con có tổng bằng k.
Gọi s là tổng các phần tử trong tập con mình đang xét.
ĐK để gọi đệ quy tại vị trí j:
- s + a_j <= k
- j < a.size().
Nếu s = k thì push kết quá vào vector đáp án.

# 25 - Tập con bằng nhau.
Gọi sum là tổng tất cả các phần tử trong A[].
- Nếu sum không chia hết cho 2, thì không thể chia thành 2 tập con bằng nhau được.
- Ngược lại đưa về bài toán tìm tập con có tổng bằng sum/2. 

# 27 - Chia mảng.
Gọi sum là tổng tất cả các phần tử trong A[].
- Nếu sum không chia hết cho k , thì không thể chia thành k tập con bằng nhau được.
- Ngược lại quay lui tìm các dãy con có tổng bằng sum/k.

# Bài 28 - Tổ hợp số có tổng bằng X.
Đặt sum = s
Tại vị trí i, gọi j bằng sum/a_i ( j là số khả năng lớn nhất sao cho sum-j*a_i >= 0 )
Với mỗi j >= 0 . Gọi đệ quy đến i + 1 với giá trị sum hiện tai.

# Bài 29 - Di chuyển trong ma trận.
Bài này các bạn có thể quay lui cũng được nhưng mình dùng toán cho nhanh.
Số cách di chuyển từ ô A[0,0] đến ô A[n-1][m-1] bằng (n+m-2)C(n-1) 
( toán rời rạc 1 đã học)

# Bài 30 - Số nguyên tố
Sàng nguyên tố để sàng những số đầu tiên nhỏ hơn 200.
Với mỗi p , dùng hàm lower_bound để tìm vị trí đầu tiên lớn hơn hoặc bằng p.
Đưa về bài toán tập con có tổng bằng s , thêm điều kiện độ dài tập con đó phải là n.

# Bài 31 - Từ điển.
Lưu ý :
Bài này ghép được từ nào in ra từ đấy , theo thứ tự từ đầu đến cuối của ma trận.
Đệ quy:
Gọi x,y là vị trí hiện tại. đánh dấu vị tri x,y là đã xét.
Thử 8 hướng của x,y , nếu vị trí mới nằm trong ma trận và chưa được đánh dấu thì gọi đệ quy đến vị trí mới.
đánh dấu vị trí x,y là chưa xét

# Bài 32 - Loại bỏ dấu ngoặc.
Gọi d là phép loại bỏ ít nhất dấu ngoặc để xâu còn lại là một biểu thức đúng.
Loại bỏ các dãy ngoặc đúng bằng stack , cuối dùng ta được d = size(stack).
Quay lui tìm tất cả các dãy ngoặc đúng , sau khi xoá d dấu ngoặc khỏi xâu.
2 trường hợp in ra -1 :
- d = len(s)
- s tồn tại duy nhất một kí tự khác dấu ngoặc và d = len(s) - 1.

Mình dùng set để lưu đáp án , tránh cho việc 2 xâu đáp án có thể trùng nhau.

# Bài 33 - Sắp xếp quân hậu 1.
Ý tưởng:
- Đầu tiên ta đặt quân hậu thứ nhất vào các cột trên hàng 1 ( có n cách đặt )
- Thử đặt quân hậu 2 vào từng cột ở hàng 2 sao cho không bị quân hậu 1 khống chế.  
- Với mỗi vị trí của quân hậu này ta lại thử đặt quân hậu thứ ba vào các cột sao cho không bị các quân hậu trước khống chế.
Sau khi đặt xong quân hậu thứ n thì kết quả tăng lên.

# Bài 35 - Tập hợp.
Bài toán tập con có tổng bằng s sao cho số lượng các phần tử trong tập hợp bằng k.

# Bài 36 - Biểu thức toán học.
Ý tưởng:
- Sinh tất cả các hoán vị của A,B,C,D,E
- Với mỗi hoán vị , sinh ra tất cả cách đặt dấu +,-,* vào biểu thức.

# Bài 37 - Đường đi dài nhất.
Ý tưởng:
- Biểu diễn đồ thị dưới dạng ma trận kề ( matrix[u][v] = 1 nếu có cạnh nối giữa u và v)
- Với mỗi đỉnh u đang xét, duyệt qua tất cả các đỉnh kề của u ( gọi đỉnh kề là v thì matrix[u][v] = 1 ) và thực hiện đệ quy tìm đường đi dài nhất.

# Bài 38 - Số nhỏ nhất có N ước số.
Với số nguyen dương m bất kì ta có.
m = (p_1^c_1)(p_2^c_2)...(p_k^c_k) voi p là cac thừa số nguyên tố.
( p_1 < p_2 < ... < p_k ) 
Đặt n là số ước của m -> n = (c_1 + 1)(c_2 + 1)...(c_k + 1) 
tìm các bộ c1,c2,..ck thoả mãn tích bằng n ( c_1 <= c_2 <= ... <= c_k). Từ đó tìm được m min
Bạn có thể tham khảo tại
https://en.m.wikipedia.org/wiki/Highly_composite_number