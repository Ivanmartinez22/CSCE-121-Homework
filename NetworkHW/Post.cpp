/*
 *
 * This code is copyrighted (c) 2021 by
 * Texas A&M Computer Science
 *
 *	There will be RIGOROUS cheat checking on your exams!!
 *	DON'T POST ANYWHERE!! such as CHEGG, public Github, etc
 *  You will be legally responsible.
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include "Post.h"
#include <sstream>
#include <iostream>
using std::string;
using std::vector;
using std::istringstream;
Post::Post(unsigned int postId, string userName, string postText)
  : postId(postId), userName(userName), postText(postText) {
  if (postId == 0 || userName == "" || postText == "") {
    throw std::invalid_argument("post constructor: invalid parameter values");
  }
}

unsigned int Post::getPostId() {
  return postId;
}

string Post::getPostUser() {
  return userName;
}

string Post::getPostText() {
  return postText;
}

vector<string> Post::findTags() {
  // TODO(student): extracts candidate tags based on occurrences of # in the post
  istringstream ss(getPostText());
  string word_check;
  vector<string> hashtags;
  unsigned int i = 0;
  while(ss >> word_check){
    if(word_check[0] == '#'){
      for(int i = 1; i < word_check.length(); i++){
        word_check[i] = tolower(word_check[i]);
      }
      if(word_check[word_check.length() - 1] == '!' || word_check[word_check.length() - 1] == ',' || word_check[word_check.length() - 1] == '.' || word_check[word_check.length() - 1] == '?'){
        word_check.erase(word_check.length() - 1);
      }
      hashtags.push_back(word_check);
    }
  }
  return hashtags;
}
