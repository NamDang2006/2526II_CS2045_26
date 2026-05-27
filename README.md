# Mô-đun Phê Duyệt Khoản Vay Cá Nhân - CS2045 Bank

Dự án triển khai mô-đun phần mềm tự động quyết định phê duyệt khoản vay dựa trên các tham số đầu vào: `age`, `income`, `credit_score`, và `employment`.

## Kỹ thuật Kiểm thử Đã Áp Dụng
* **Phân hoạch tương đương (EP)** & **Phân tích giá trị biên (BVA)** cho dữ liệu đầu vào.
* **Bảng quyết định (Decision Table)** tối ưu hóa để bao phủ các kịch bản nghiệp vụ.

## Cách Chạy Chương Trình C++
Bạn có thể biên dịch và chạy file `main.cpp` bằng bất kỳ trình biên dịch C++ nào hỗ trợ C++11 trở lên:

```bash
g++ -std=c++11 main.cpp -o loan_test
./loan_test
