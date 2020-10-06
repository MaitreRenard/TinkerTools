project('jwt', 'c', version : '0.1',
	default_options : [
		'warning_level=3',
		'c_std=c18'
	]
)

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

cc = meson.get_compiler('c')
b64_dep = cc.find_library('b64', required : false)
json_dep = cc.find_library('json', required : false)

add_project_arguments(cc.get_supported_arguments(security_cc_flags), language : 'c')
add_project_link_arguments(cc.get_supported_link_arguments(security_link_flags), language : 'c')

executable('jwt', 'jwt.c', dependencies : [ b64_dep, json_dep ] )
