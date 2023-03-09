//
// Created by Gavin Taylor Mcroy on 12/2/22.
//

#ifndef BEIER_NEELY_ALGORITHM_LINESEGMENT_H
#define BEIER_NEELY_ALGORITHM_LINESEGMENT_H

#include <fstream>

class LineSegment {
private:
    std::fstream loadSegments(const std::string& fileName);

public:
    LineSegment();


};


#endif //BEIER_NEELY_ALGORITHM_LINESEGMENT_H
