/*
 *
 * This code is copyrighted (c) 2021 by
 * Texas A&M Computer Science
 *
 *	There will be RIGOROUS cheat checking on your exams!!
 *	DON'T POST ANYWHERE!! such as CHEGG, public Github, etc
 *  You will be legally responsible.
 */

#include <string>
#include <stdexcept>
#include "User.h"
#include <iostream>

using std::string;
using std::vector;
using std::invalid_argument;
using std::cout;
using std::endl;
User::User(string userName) : userName(userName) {
  // TODO(student): implement constructor checks
  if(userName == ""){
    throw std::invalid_argument("Invalid Argument");
  }
  for(int i = 0; i < userName.length(); i++){
    if(userName[i] < 97 || userName[i] > 122){
      throw std::invalid_argument("Invalid Argument");
    }
  }
}

string User::getUserName() {

  // TODO(student): implement getter
  return userName;
}

vector<Post*>& User::getUserPosts() {
  // TODO(student): implement getter
  return userPosts;
}

void User::addUserPost(Post* post) {
  // TODO(student): add post to user posts
  if(post == nullptr){
    throw std::invalid_argument("Invalid Argument");
  }
  // cout << "post added " << User(userName).getUserName() << endl;
  userPosts.push_back(post);
}
