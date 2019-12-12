//
//  RW_File.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/12/05.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <string>

/* 파일 전체를 한 번에 읽기 */
//int main() {
//  // 파일 읽기 준비
//  std::ifstream in("/Users/jeenee/documents/projects/algorithms-CPP/test.txt");
//  std::string s;
//
//  if (in.is_open()) {
//    // 위치 지정자를 파일 끝으로 옮긴다.
//    in.seekg(0, std::ios::end);
//
//    // 그리고 그 위치를 읽는다. (파일의 크기)
//    int size = (int)in.tellg();
//
//    // 그 크기의 문자열을 할당한다.
//    s.resize(size);
//
//    // 위치 지정자를 다시 파일 맨 앞으로 옮긴다.
//    in.seekg(0, std::ios::beg);
//
//    // 파일 전체 내용을 읽어서 문자열에 저장한다.
//    in.read(&s[0], size);
//    std::cout << s << std::endl;
//  } else {
//    std::cout << "파일을 찾을 수 없습니다!" << std::endl;
//  }
//  return 0;
//}



///* 파일 전체를 한 줄씩 읽기 */
//int main() {
//  // 파일 읽기 준비
//  std::ifstream in("/Users/jeenee/documents/projects/Algorithms-CPP/test.txt");
//  char buf[100];
//
//  if (!in.is_open()) {
//    std::cout << "파일을 찾을 수 없습니다!" << std::endl;
//    return 0;
//  }
//
//  while (in) {
//    in.getline(buf, 100);
//    std::cout << buf << std::endl;
//  }
//
//  return 0;
//}



/* string의 getline으로 한 줄씩 읽기*/
int main() {
  // 파일 읽기 준비
    std::ifstream in("/Users/jeenee/documents/projects/Algorithms-CPP/test.txt");

  if (!in.is_open()) {
    std::cout << "파일을 찾을 수 없습니다!" << std::endl;
    return 0;
  }

  std::string s;
  while (true) {
    getline(in, s);
    std::cout << s << std::endl;
      if (in.eof()) break;
  }

  return 0;
}



/* 파일 쓰기 */
//#include <iostream>
//#include <fstream>
//#include <string>
//
//int main() {
//  // 파일 쓰기 준비(기존 내용 삭제)
//  std::ofstream out("/Users/jeenee/documents/projects/algorithms-CPP/test.txt");
//    // ios::app 옵션을 추가하면 덧붙일 수 있다.
////    std::ofstream out("/Users/jeenee/documents/projects/algorithms-CPP/test.txt", std::ios::app);
//
//  std::string s;
//  if (out.is_open()) {
//    out << "이걸 쓰자~~ㅇㅇ";
//  }
//
//  return 0;
//}
