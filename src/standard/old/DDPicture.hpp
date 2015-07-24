// DDPicture.hpp



 #include "DDGlobal.hpp"//"DDGraphic.hpp"



DD_BEGIN
 #if _WIN32 > 0
class DDBitmap {
    public:
    
    private:
    struct {
        public:
        ShortCodeType file_type;
        SizeType file_size;
        ShortCodeType reserved_1;
        ShortCodeType reserved_2;
        LengthType off_bits;
        
    } head = {sizeof(DDBitmap), 0L, 0, 0, 0L};
    struct {
        public:
        SizeType info_size;
        LengthType width;
        LengthType height;
        ShortCodeType plane;
        LengthType bit_length;
        LongCodeType compression;
        SizeType image_size;
        ;
        
    } info = {sizeof(info), 0L, 0L, 0, 0L, 0, 0L, };
    
}


 #endif


DD_END