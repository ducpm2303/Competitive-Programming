### Contest 3
# Bài 1 : Đổi tiền 
Dễ thấy nếu trừ dần tiền đi cho những tờ tiền có mệnh giá to trước thì tối ưu nhất.
# Bài 2 : Nhầm chứ số
Tổng nhỏ nhất : chứ số 6 thay bằng 5
Tổng lớn nhất : chữ số 5 thay bằng 6
# Bài 3 : Tìm Max
Sắp xếp mảng A tăng dần thì tối ưu nhất , lưu ý lấy dư cho 10^9 + 7.
# Bài 4 : Tổng nhỏ nhất
Sắp xếp mảng A . Số đầu tiên sẽ được tạo thành từ những những vị trí chẵn , số thứ 2 được tạo từ những vị trí lẻ.
# Bài 5 : Chia mảng
Sắp xếp mảng A . tập đầu tiên có min(k,n-k) phần tử đầu tiên, tập thứ 2 gồm những phần tử còn lại
# Bài 6 : Sắp xếp tham lam
Tạo mảng B = A .
Sắp xếp mảng A . Dễ thấy với một vị trí i bất kì thì a[i] chỉ có được 2 vị trí là i và n - i - 1 ( tính chất đảo ngược của đầu bài) . 
Giờ quay lại lúc trưa sắp xếp là mảng B . Nếu b[i] nằm sai vị trí ( i != vtb[i]) thì in ra No
# Bài 7 : Giá trị nhỏ nhất của biểu thức
Sắp xếp mảng a tăng dần , b giảm dần
Kết quả là \sum_{i=0}^{n-1} a_i*b_i
# Bài 8 : Sắp xếp công việc
Sắp xếp thời gian theo thời gian kết thúc
Duyệt trâu tìm kết quả
# Bài 10 : Nối dây 1 
Để tối ưu chi phí thì mỗi lần chọn phải chọn 2 sợi dây nhỏ nhất.
Sử dụng hàng đợi ưu tiên rất thích hợp để xử lý bài này.
# Bài 11 : Nối dây 2
Tương tự bài 10 nhưng mod trước khi push vào queue
# Bài 12 : Sắp đặt xâu kí tự 1
Gọi cnt là số lần xuất hiện nhiều nhất của một chữ cái.
Tổng số lần xuất hiện các chữ số còn lại > cnt thì in ra 1 , ngược lại in ra 0.
# Bài 13 : Sắp đặt xâu kí tự 2
gọi cntmax là chữ số xuất hiện nhiều nhất . Kiểm tra xem (cntmax-1)*d có nhỏ hơn len(s) hay ko là được.
# Bài 14 : Số khối lập phương
Do n <= 10^18 nên mình sinh nhị phân ( độ dài của xâu nhị phân max = 19)
Với mỗi xâu nhị phân thì cho ra một số , kiểm tra xem số đó cỏ phải số lập phương hay ko và cập nhập kết quả.
# Bài 15 : Mua lương thực
# Bài 16 : Số nhỏ nhất
- Nếu s > 9* d thì ko có đáp án
- Khởi tạo mảng có d phần tử , tối ưu sao cho mảng d ko giảm (a[0] != 0)
# Bài 17 : Giá trị nhỏ nhất của xâu
Mỗi lần loại bỏ , loại bỏ đi kí tự xuất hiện nhiều nhất trong mảng.
Dùng hàng đợi ưu tiên
# Bài 18
Giả sử có phương trình 
4y + 7z = n --> (4y + 7z)(mod 7) = n(mod 7)
-> 4y (mod 7) = n(mod 7) = x;
Tính chất đồng dư : 4y = (x + 7*p) ( p >= 0 && x + 7*p <= n)
Tìm ra cặp nghiệm y,z đầu tiên thỏa mãn phương trình trên.
# Bài 19
Trừ dần phân số đến khi tử bằng 1. 
# Bài 20
