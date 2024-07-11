/*
    Student Name         : Jian Ira Olvido Farne
    UOWID                : 7433645
    Tutorial Class       : T01
    Asssignment          : 03
*/

#ifndef MYTEMPLATES_H
#define MYTEMPLATES_H

template <typename T>
double scalar_difference(const T& a, const T& b) {
    double difference;
	difference = fabs(a.getScalarValue() - b.getScalarValue());
	return difference;
}

template <typename T>
bool equals(const T& a, const T& b) {
    if (a == b){
        return true;
    }
    else{
        return false;
    } 
}

//To sort by x-ordinate and ASC
struct Point2D_SortByX_ASC{
    template <typename T>
    bool operator() (const T& a, const T& b) const {
        return (a.getX() < b.getX());
    }
};

//To sort by x-ordinate and DSC
struct Point2D_SortByX_DSC{
    template <typename T>
    bool operator() (const T& a, const T& b) const {
        return (a.getX() > b.getX());
    }
};

//To sort by y-ordinate and ASC
struct Point2D_SortByY_ASC{
    template <typename T>
    bool operator() (const T& a, const T& b) const {
        return (a.getY() < b.getY());
    }
}; 

//To sort by y-ordinate and DSC
struct Point2D_SortByY_DSC{
    template <typename T>
    bool operator() (const T& a, const T& b) const {
        return (a.getY() > b.getY());
    }
};

//To sort by distance from origin and ASC
struct Point2D_SortByDistFrOri_ASC {
    template <typename T>
    bool operator() (const T& a, const T& b) const {
        return (a.getScalarValue() < b.getScalarValue());
    }
};

//To sort by distance from origin and DSC
struct Point2D_SortByDistFrOri_DSC {
    template <typename T>
    bool operator() (const T& a, const T& b) const {
        return (a.getScalarValue() > b.getScalarValue());
    }
};

//To sort by x-ordinate and ASC
struct Point3D_SortByX_ASC{
    template <typename T>
    bool operator() (const T& a, const T& b) const {
        return (a.getX() < b.getX());
    }
};

//To sort by x-ordinate and DSC
struct Point3D_SortByX_DSC{
    template <typename T>
    bool operator() (const T& a, const T& b) const {
        return (a.getX() > b.getX());
    }
};

//To sort by y-ordinate and ASC
struct Point3D_SortByY_ASC{
    template <typename T>
    bool operator() (const T& a, const T& b) const {
        return (a.getY() < b.getY());
    }
};

//To sort by y-ordinate and DSC
struct Point3D_SortByY_DSC{
    template <typename T>
    bool operator() (const T& a, const T& b) const {
        return (a.getY() > b.getY());
    }
};

//To sort by z-ordinate and ASC
struct Point3D_SortByZ_ASC {
    template <typename T>
    bool operator() (const T& a, const T& b) const {
        // Ascending uses <
        return (a.getZ() < b.getZ());
    }
};

//To sort by z-ordinate and DSC
struct Point3D_SortByZ_DSC{
    template <typename T>
    bool operator() (const T& a, const T& b) const {
        return (a.getZ() > b.getZ());
    }
};
 
//To sort by distance from origin and ASC
struct Point3D_SortByDistFrOri_ASC {
    template <typename T>
    bool operator() (const T& a, const T& b) const {
        return (a.getScalarValue() < b.getScalarValue());
    }
};

//To sort by distance from origin and DSC
struct Point3D_SortByDistFrOri_DSC {
    template <typename T>
    bool operator() (const T& a, const T& b) const {
        return (a.getScalarValue() > b.getScalarValue());
    }
};

//To sort by Point 1 and ASC
struct SortByPt1_ASC {
    template <typename T>
    bool operator() (const T& a, const T& b) const {
        if (a.getPt1().getX() == b.getPt1().getX()) {
            return (a.getPt1().getY() < b.getPt1().getY());
        }
        else{ 
            return (a.getPt1().getX() < b.getPt1().getX());
        }
    }
};

//To sort by Point 1 and DSC
struct SortByPt1_DSC {
    template <typename T>
    bool operator() (const T& a, const T& b) const {
        if (a.getPt1().getX() == b.getPt1().getX()) {
            return (a.getPt1().getY() > b.getPt1().getY());
        }
        else{ 
            return (a.getPt1().getX() > b.getPt1().getX());
        }
    }
};

//To sort by Point 2 and ASC
struct SortByPt2_ASC {
    template <typename T>
    bool operator() (const T& a, const T& b) const {
        if (a.getPt2().getX() == b.getPt2().getX()) {
            return (a.getPt2().getY() < b.getPt2().getY());
        }
        else{ 
            return (a.getPt2().getX() < b.getPt2().getX());
        }
    }
};

//To srt by Point 2 and DSC
struct SortByPt2_DSC {
    template <typename T>
    bool operator() (const T& a, const T& b) const {
        if (a.getPt2().getX() == b.getPt2().getX()) {
            return (a.getPt2().getY() > b.getPt2().getY());
        }
        else{ 
            return (a.getPt2().getX() > b.getPt2().getX());
        }
    }
};

//To sort by length and ASC
struct SortByLength_ASC {
    template <typename T>
     bool operator() (const T& a, const T& b) const {
         return (a.getScalarValue() < b.getScalarValue());
     }
};

//To sort by length and DSC
struct SortByLength_DSC {
    template <typename T>
     bool operator() (const T& a, const T& b) const {
         return (a.getScalarValue() > b.getScalarValue());
     }
};

#endif