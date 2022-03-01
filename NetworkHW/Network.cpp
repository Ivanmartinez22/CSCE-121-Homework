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
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Network.h"

using std::string;
using std::vector;
using std::ifstream;
using std::cout;
using std::endl;
using std::istringstream;
using std::runtime_error;

Network::Network() {
  // empty containers of vectors already created
  // no implementation is needed here
}

void Network::loadFromFile(string fileName) {
  // TODO(student): load user and post information from file
  ifstream ifs (fileName);
	if (!ifs.is_open()){
    throw std::invalid_argument("Invalid Argument3");
  }
  string lineread;
  while(getline(ifs, lineread)){
    istringstream ss(lineread);
    string split_point;
    ss >> split_point;
    bool permission = false;
    if(split_point == "Post"){
      permission = true;
    }
    if(split_point == "User"){
      permission = true;
    }
    if(permission == false){
      throw std::runtime_error("Invalid Format1");
    }
    try{
      if(split_point == "Post"){
        string IDstr;
        unsigned int ID;
        ss >> IDstr;
        ID = stoi(IDstr);
        string username;
        ss >> username;
        string post_text;
        string read_text;
        while(ss >> read_text){
          post_text.append(read_text);
          post_text.append(" ");
        }
        post_text.erase(post_text.length() - 1);
        addPost(ID, username, post_text);

      }
      else if(split_point == "User"){
        string username;
        ss >> username;
        addUser(username);
      }
    }
    catch(std::exception& exc){
      throw std::runtime_error("Invalid Format2");
    }
  } 
}

void Network::addUser(string userName) {
  // TODO(student): create user and add it to network
  User* pointer = new User(userName);
  users.push_back(pointer);
  cout << "Added User " << userName << endl;
}

void Network::addPost(unsigned int postId, string userName, string postText) {
  // TODO(student): create post and add it to network
  Post* pointer = new Post(postId, userName, postText);
  
  for(unsigned int i = 0; i < posts.size(); i++){
    if(pointer->getPostId() == posts.at(i)->getPostId()){
      throw std::invalid_argument("Invalid Argument2");
    }
  }
  bool permission = false;
  unsigned int index;
  for(unsigned int i = 0; i < users.size(); i++){
    if(userName == users.at(i)->getUserName()){
      permission = true;
      // cout << " permission granted " << endl;
      index = i;
    }
  }
  if(permission == false){
    throw std::invalid_argument("Invalid Argument");
  }
  posts.push_back(pointer);
  (users.at(index))->addUserPost(pointer);
  vector<string> localtags = pointer->findTags();
  for(unsigned int i =0; i < localtags.size(); i++){
    string checktag = localtags.at(i);
    bool check = false;
    unsigned int index;
    for(unsigned int i = 0; i < tags.size(); i++){
      if(checktag == tags.at(i)->getTagName()){
        check = true;
        tags.at(i)->addTagPost(pointer);
      }
    }
    if(check == false){
      try{
        Tag* addedTag = new Tag(checktag);
        tags.push_back(addedTag);
        addedTag->addTagPost(pointer);
      }
      catch(std::exception& exc){}
    }

  } 
  cout << "Added Post " << postId << " by " << userName << endl;
}

vector<Post*> Network::getPostsByUser(string userName) {
  // TODO(student): return posts created by the given user
  if(userName == ""){throw std::invalid_argument("Invalid Argument Here");}
  bool check = false;
  unsigned int index;
  for(unsigned int i = 0; i < users.size(); i++){
    if(userName == (users.at(i))->getUserName()){
      check = true;
      index = i;
    }
  }
  if(check == false){throw std::invalid_argument("Invalid Argument");}

  return (users.at(index))->getUserPosts();
}

vector<Post*> Network::getPostsWithTag(string tagName) {
  // TODO(student): return posts containing the given tag
  if(tagName == ""){throw std::invalid_argument("Invalid Argument");}
  bool check = false;
  unsigned int index;
  for(unsigned int i = 0; i < tags.size(); i++){
    if(tagName == (tags.at(i))->getTagName()){
      check = true;
      index = i;
    }
  }
  if(check == false){throw std::invalid_argument("Invalid Argument");}
  return (tags.at(index))->getTagPosts();
}

vector<string> Network::getMostPopularHashtag() {
  // TODO(student): return the tag occurring in most posts
  if(tags.size() == 0){
    vector<string> empty;
    return empty;
  }
  string maxTag;
  maxTag = tags.at(0)->getTagName();
  int max = tags.at(0)->getTagPosts().size();
  vector<string> maxTags;
  bool equality_flag = false;
  for(unsigned int i = 0; i < tags.size(); i++){
    int size = tags.at(i)->getTagPosts().size();
    if(size > max){
      max = size;
      maxTag = tags.at(i)->getTagName();
      equality_flag = false;
    }
    else if(size == max){
      equality_flag = true;
    }
  }
  if(equality_flag == false){
    maxTags.push_back(maxTag);
  }
  else if(equality_flag == true){
    for(unsigned int i = 0; i < tags.size(); i++){
      int size = tags.at(i)->getTagPosts().size();
      if(size > max){
        max = size;
        maxTag = tags.at(i)->getTagName();
      }
      else if(size == max){
        maxTags.push_back(tags.at(i)->getTagName());
      }
    }
  }
  

  return maxTags;
}

/**
  * Destructor
  * Do not change; already implemented.
  */
Network::~Network() {
  for (unsigned int i = 0; i < users.size(); ++i) {
    delete users.at(i);
  }
  for (unsigned int i = 0; i < tags.size(); ++i) {
    delete tags.at(i);
  }
  for (unsigned int i = 0; i < posts.size(); ++i) {
    delete posts.at(i);
  }
}
