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
#include "Tag.h"

using std::string;
using std::vector;

Tag::Tag(string tagName) : tagName(tagName) /* TODO(student): initialize */ {
  // TODO(student): implement constructor checks
  if(tagName.length() < 2){
    throw std::invalid_argument("Invalid Argument");
  }
  else if(tagName[0] != '#'){
    throw std::invalid_argument("Invalid Argument");
  }
  else if(tagName[1] < 97 || tagName[1] > 122){
    throw std::invalid_argument("Invalid Argument");
  }
  for(int i = 1; i < tagName.length(); i++){
    if(tagName[i] < 97 || tagName[i] > 122){
      throw std::invalid_argument("Invalid Argument");
    }
  }
}

string Tag::getTagName() {
  // TODO(student): implement getter
  return tagName;
}

vector<Post*>& Tag::getTagPosts() {
  // TODO(student): implement getter
  return tagPosts;
}

void Tag::addTagPost(Post* post) {
  // TODO(student): add post to tag posts
  if(post == nullptr){
    throw std::invalid_argument("Invalid Argument");
  }
  tagPosts.push_back(post);
  
}
