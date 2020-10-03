project('steg', 'c',
	version : '0.2',
	default_options : [
		'warning_level=3',
		'c_std=c18'
	]
)

# Get math library
cc = meson.get_compiler('c')
m_dep = cc.find_library('m', required : false)

# Strip binary, optimize it and make it position independent

# Define security flags
security_link_flags = [
	'-Wl,-z,relro',
	'-Wl,-z,now',
]

security_cc_flags = [
	'-fstack-protector',
	'-fstack-protector-strong',
	'--param=ssp-buffer-size=4',
]
add_project_arguments(cc.get_supported_arguments(security_cc_flags), language : 'c')
add_project_link_arguments(cc.get_supported_link_arguments(security_link_flags), language : 'c')


executable('lsb', 'lsb.c', dependencies : m_dep)
