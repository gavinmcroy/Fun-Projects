//
// Created by Gavin Taylor Mcroy on 9/26/2020 AD.
//

#include "StoredWebPages.h"

std::vector<StoredWebPages::Webpage>&StoredWebPages::getWebPages(){
    return pages;
}
StoredWebPages::StoredWebPages(int alloc){
    pages.reserve(alloc);
}