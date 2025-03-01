#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

Corpus tokenize(const std::string& source) {
  /* TODO: Implement this method */
  Corpus res;
  auto space=find_all(source.begin(),source.end(),isspace);
  
  std::transform(space.begin(),space.end()-1,space.begin()+1,std::inserter(res,res.end()),[&source](auto a,auto b){
    return Token(source,a,b);
  });
  std::erase_if(res,[](Token a){return a.content.empty();});
  return res;
}

std::set<Mispelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
  namespace rv = std::ranges::views;
  auto view = source 
  | rv::filter([&dictionary](Token a) { return !dictionary.contains(a.content); })
  | rv::transform([&dictionary](Token a) {
      auto suggestions = dictionary 
        | rv::filter([&](std::string dic) { return levenshtein(a.content, dic) == 1; })
        | rv::transform([](std::string s) { return s; });  
      std::set<std::string> set_suggestions(suggestions.begin(), suggestions.end());
      return Mispelling(a, set_suggestions);  
    })
  | rv::filter([](const Mispelling& m) { return !m.suggestions.empty(); });  

  return std::set<Mispelling>(view.begin(), view.end());
}

/* Helper methods */

#include "utils.cpp"