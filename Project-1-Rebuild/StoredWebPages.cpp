//
// Created by Gavin Taylor Mcroy on 1/20/23.
//

#include "StoredWebPages.h"

std::vector<StoredWebPages::Webpage>&StoredWebPages::getWebPages(){
    return pages;
}
StoredWebPages::StoredWebPages(int alloc){
    pages.reserve(alloc);
}