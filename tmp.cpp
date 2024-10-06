bool eql(const computorv2::Object*              left, const computorv2::Object*              right);
bool eql(const computorv2::Complex&             left, const computorv2::Complex&             right);
bool eql(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right);
bool eql(const computorv2::UsualFunction&       left, const computorv2::UsualFunction&       right);
bool eql(const computorv2::Polynomial&          left, const computorv2::Polynomial&          right);
bool eql(const computorv2::Complex&             left, const computorv2::IndependentVariable& right);
bool eql(const computorv2::IndependentVariable& left, const computorv2::Complex&             right);
bool eql(const computorv2::Complex&             left, const computorv2::UsualFunction&       right);
bool eql(const computorv2::UsualFunction&       left, const computorv2::Complex&             right);
bool eql(const computorv2::Complex&             left, const computorv2::Polynomial&          right);
bool eql(const computorv2::Polynomial&          left, const computorv2::Complex&             right);
bool eql(const computorv2::IndependentVariable& left, const computorv2::UsualFunction&       right);
bool eql(const computorv2::UsualFunction&       left, const computorv2::IndependentVariable& right);
bool eql(const computorv2::IndependentVariable& left, const computorv2::Polynomial&          right);
bool eql(const computorv2::Polynomial&          left, const computorv2::IndependentVariable& right);
bool eql(const computorv2::UsualFunction&       left, const computorv2::Polynomial&          right);
bool eql(const computorv2::Polynomial&          left, const computorv2::UsualFunction&       right);